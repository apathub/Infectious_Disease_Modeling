for i in {500..1000..100}
do
	for j in $(seq 0.0 0.1 1.0);
	do
		for k in $(seq 0.0 0.1 1.0);
		do
			for l in {0..50..10}
			do
				./CompE5<<EOF
				$i
				$j
				$k
				$l
EOF
			done
		done
	done
done
exit 0
