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

SHORT=c:,d:,p:,w:,h:,s:,o:,f:,F:,G:,S:,A:,O:,Q:,help
#LONG=col:,date:,pression:,vent:,height:,station:,output:,file:,France:,Guyane:,SaintPierre:,Antilles:,Ocean,help
LONG=col:,date:,pression:,vent:,height:,station:,output:,file:,help
OPTS=$(getopt --options $SHORT --long $LONG --name "$0" -- "$@")
eval set -- "$OPTS"
while :
do
    case "$1" in
        -c | --col)
            col="$2"
            shift 2
            ;;
        -f | --file)
            file="$2"
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
        -F | --France)
            pays="France"
            shift 2
            ;;
        -G | --Guyane)
            pays="Guyane"
            shift 2
            ;;
        -S | --SaintPierre)
            pays="Saint-Pierre et Miquelon"
            shift 2
            ;;
        -A | --Antilles)
            pays="Antilles"
            shift 2
            ;;
        -O | --Ocean)
            pays="Océan indien"
            shift 2
            ;;
        -Q | Antractique)
            pays="Antarctique"
            shift 2
            ;;
        --avl)
            algo="avl"
            shift 2
            ;;
        --abr)
            algo="abr"
            shift 2
            ;;
        --tab)
            algo="tab"
            shift 2
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
echo "col: $col date: $date pression: $pression vent: $vent hauteur station: $height station: $station output: $output"

# si pression = 1 =>produit en sortie les températures 
#min et max et moyenne par station dans l'ordre croissant de numero de station

#si pression = 2 =>produit en sortie les températures moyennes
# par data/heure trié chronologiquement
