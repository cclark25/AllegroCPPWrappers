cat temp.text | while read line; do {
	type=$(echo $line | cut -d ' ' -f 1);
	rest=$(echo $line | cut -d ' ' -f 2- | sed -e 's/;/\{\}/');
	echo "$type Transform::$rest";
};
done;