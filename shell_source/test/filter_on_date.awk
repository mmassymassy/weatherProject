BEGIN {
        srt = "date -d " start " +%s"
        srt | getline start
        close(srt)
        ed = "date -d " end " +%s"
        ed | getline end
        close(ed)
}

{
        bkp = $1
        print bkp
        epoch = "date -d" $2 " +%s"
        epoch | getline $2
        close(epoch)
}

($1 >= start && $1 <= end) {
        print bkp
}
