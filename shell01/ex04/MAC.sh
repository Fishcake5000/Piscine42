ifconfig -a link | grep "ether" | tr -d '\t' | cut -d ' ' -f 2
