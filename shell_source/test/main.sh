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

SHORT=c:,d:,p:,w:,h:,s:,o:,help
LONG=col:,date:,pression:,vent:,humidity:,station:,output:
OPTS=$(getopt --options $SHORT --long $LONG --name "$0" -- "$@")
eval set -- "$OPTS"
while :
do
    case "$1" in
        -c | --col)
            col="$2"
            shift 2
            ;;
        -d | --date)
            date="$2"
            shift 2
            ;;
        -p | --pression)
            pression="$2"
            shift 2
            ;;
        -w | --wind)
            vent="$2"
            shift 2
            ;;
        -h | --height)
            height="$2"
            shift 2
            ;;
        -s | --station)0
            station="$2"
            shift 2
            ;;
        -o | --output)
            output="$2"
            shift 2
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
echo "col: $col date: $date pression: $pression vent: $vent hauteur station: $height station: $station output: $output"

# si pression = 1 =>produit en sortie les températures 
#min et max et moyenne par station dans l'ordre croissant de numero de station

#si pression = 2 =>produit en sortie les températures moyennes
# par data/heure trié chronologiquement
