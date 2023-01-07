{
    group[$1] = (group[$1] == "" ? $2 : group[$1] RS $2 )
}

END {
    for (group_name in group){
        x++
    }
    print 1
    print x
    print 1
    for (group_name in group){
        print group_name
        print group[group_name]
        printf "\n"
    }
}