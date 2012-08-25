SOURCE=$1

echo -n "</script><script>eval(String.fromCharCode("
hexdump -v -e '"" 1/1 "%d, " ""' $SOURCE
echo "32));</script><script>"

