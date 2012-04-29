#!/bin/sh#
cat $1 | sed '/^[a-z]/ d' | sed '/^\	/ d' | sed '/^\-/ d' |
	sed '/^Black\-Scholes/ d' |
	sed '/^Trials/ d' |
	sed '/^Confidence/ d' |
	sed '/^Average/ d' |
	sed '/^Standard/ d' |
	sed 's/(.*)//g' |
	if [ $# -eq 1 ]; then
			  sed 's/Total[a-zA-Z ]*/Total/g' | 
			  sed 's/PRNG[a-zA-Z ]*/PRNG/g' |
			  sed 's/BS[a-zA-Z ]*/BS/g' 
	else 
			  # print total only
			  if [ $2 -eq 0 ] ; then
						 sed 's/Total[a-zA-Z ]*/Total/g' |
						 sed '/^PRNG/ d' |
						 sed '/^BS/ d'
			  fi
			  # print PRNG only
			  if [ $2 -eq 1 ] ; then
						 sed '/^Total/ d' |
						 sed '/^BS/ d' |
						 sed 's/PRNG[a-zA-Z ]*/PRNG/g'
			  fi
			  #print BS only
			  if [ $2 -eq 2 ] ; then
						 sed '/^Total/ d' |
						 sed '/^PRNG/ d' |
						 sed 's/BS[a-zA-Z ]*/BS/g' 
			  fi
	fi

	#sed 's/(.*)//g' |
#	sed '/^Total/ d' |
	#sed 's/Total[a-zA-Z ]*/Total/g' |
#	sed '/^PRNG/ d' |
	#sed 's/PRNG[a-zA-Z ]*/PRNG/g' |
#	sed '/^BS/ d'
	#sed 's/BS[a-zA-Z ]*/BS/g' 


#declare -a ARRAY

#Link filedescriptor 10 with stdin
#exec 10<&0

# stdin replaced with a file supplied as a first argument
#exec < $1
#let count=0

#while read LINE; do
#		  ARRAY[$count]=$LINE
#		  ((count++))
#		  echo ${ARRAY[count]}
#done

# echo Number of elements: ${#ARRAY[@]}
#echo ${ARRAY[@]}
#echo count = $count


# restore stdin from filedescriptor 10
# and close filedescriptor 10
#exec 0<&10 10<&-
