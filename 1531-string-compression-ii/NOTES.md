/*
3 cases:
case 1: We will delete our current character if K is available, so our string length will be minimum.
case 2: If cur char is not same as prev, our res will be increased by 1 and curCharFreqCount will be 1
case 3: If cur char is same as prev char, we need to merge it and increase our count
case 3.1: If curCharFreqCount is either 1 or more than 9, our res will be increased by 1
case 3.2: Else, we just need to increase curCharFreqCount.
*/