#!/bin/bash


# get script's multiple options and arguments
# -t : temperature
# -h : altitude
# -p : pression
# -w : wind
# -d : date
# -s : station
# -o : output
# -c : column
# -h : help


SHORT="p:,t:,w,h,m,s:,d:,o:,f:,F,G,S,A,O,Q"
LONG="help,abr,avl,tab"

OPTS=$(getopt --options $SHORT --long $LONG --name "$0" -- "$@")
eval set -- "$OPTS"

while :
do
    case "$1" in
        
        # parse location done
        -[A-Z])
            if [[ -v pays ]];
            then
                echo "You may only provide one argument from places arguments -F -G -S -A -O -Q"
                exit
            else
                case "$1" in
                    -F | --France)
                        pays="France"
                        shift 1
                    ;;
                    -G | --Guyane)
                        pays="Guyane"
                        shift 1
                    ;;
                    -S | --SaintPierre)
                        pays="Saint-Pierre et Miquelon"
                        shift 1
                    ;;
                    -A | --Antilles)
                        pays="Antilles"
                        shift 1
                    ;;
                    -O | --Ocean)
                        pays="Océan indien"
                        shift 1
                    ;;
                    -Q | Antractique)
                        pays="Antarctique"
                        shift 1
                    ;;
                esac
            fi
        ;;
        
        # parse file done
        -f | --file)
            file="$2"
            if(! test -f $file)
            then
                echo "Le fichier $file n'existe pas"
                exit 1
            fi
            shift 2
        ;;
        
        # parse date done
        -d | --date)
            filter_date=true
            date_min="$2"
            date_max="$4"
            shift 2
        ;;
        
        # parse pression done
        -p | --pression)
            if test "$2" = "1" || test "$2" = "2" || test "$2" = "3"
            then
                is_pression=true
                pression_mode="$2"
                shift 2
            else
                echo "wrong mode provided for option -p"
                exit
            fi
            
        ;;
        
        # parse pression done
        -t)
            if test "$2" = "1" || test "$2" = "2" || test "$2" = "3"
            then
                is_temperature=true
                temperature_mode="$2"
                shift 2
            else
                echo "wrong mode provided for option -t"
                exit
            fi
        ;;
        
        # parse wind done
        -w | --wind)
            is_wind=true
            shift 1
        ;;
        
        # parse height
        -h | --height)
            is_height=true
            shift 1
        ;;
        
        # parse humidity
        -m )
            is_humidity=true
            shift 1
        ;;
        
        -o | --output)
            output="$2"
            if(! test -f $output)
            then
                output="output.txt"
            fi
            shift 2
        ;;
        
        --avl | --abr | --tab)
            if [[ -v algo ]];
            then
                echo "You may only provide one argument from algorithms arguments"
                exit
            else
                case $1 in
                    --avl)
                        algo="avl"
                        shift 1
                    ;;
                    --abr)
                        algo="abr"
                        shift 1
                    ;;
                    --tab)
                        algo="tab"
                        shift 1
                    ;;
                esac
            fi
            
            
        ;;
        --help)
            echo "Usage: $0 [options] [arguments]"
            echo "Options:"
            echo "-c, --col: column"
            echo "-d, --date: date"
            echo "-p, --pression: pression"
            echo "-w, --wind: wind"
            echo "-h, --height: height"
            echo "-s, --station: station"
            echo "-o, --output: output"
            echo "-f, --file: file"
            echo "-F, --France: France"
            echo "-G, --Guyane: Guyane"
            echo "-S, --SaintPierre: Saint-Pierre et Miquelon"
            echo "-A, --Antilles: Antilles"
            echo "-O, --Ocean: Océan indien"
            echo "-Q, --Antarctique: Antarctique"
            echo "--avl: trier avec l'algorithme avl"
            echo "--abr: trier avec l'algorithme abr"
            echo "--tab: trier en utilisant des tableaux ou listes chainées"
            echo "--help: afficher ce message d'aide"
            exit 0
        ;;
        --)
            shift
            break
        ;;
        *)
            echo "Internal error!"
            exit 1
        ;;
    esac
done


echo "date_min: $date_min  date_max: $date_max"
echo "pay: $pays"
echo "file: $file"
echo "pression: $is_pression, mode:$pression_mode"
echo "temperature: $is_temperature, temperature_mode: $temperature_mode"
echo "win: $is_wind"
echo "height: $is_height"
echo "humidity: $is_humidity"
echo "algo: $algo"


cd "${BASH_SOURCE%/*}"

col_station_id=1
col_date=2
col_pression=3
col_dir_vent=6
col_vit_vent=7
col_humidity=10

input_file="../../data/input/small_test_data.csv"
output_file="../../data/output/temp.txt"

col_station_id=1
col_date=2
col_pression=3
col_dir_vent=6
col_vit_vent=7
col_humidity=10

cols="$col_station_id,$col_date,$col_pression"

cut -d";" -f"$cols"  $input_file > temp.txt

# date format YYYY-MM-DD
echo "here"

if ( test $filter_date = true );then
    awk -F ";" -v start="$date_min" -v end="$date_max" -f ./filter_on_date.awk ./temp.txt 
fi



