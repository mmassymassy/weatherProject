cd "${BASH_SOURCE%/*}"

col_station_id=1
col_date=2
col_pression=3
col_dir_vent=6
col_vit_vent=7
col_humidity=10

input_file="../../data/input/small_test_data.csv"
output_file="../../data/output/temp.txt"


cut -d";" -f"$col_humidity","$col_station_id"  $input_file > temp.txt

rm "$output_file"
awk -F ";" -f ./humidity.awk ./temp.txt > "$output_file"

/home/abdou/repos/weatherProject/c_source/src/main "/home/abdou/repos/weatherProject/data/output/temp.txt"
echo "bla"