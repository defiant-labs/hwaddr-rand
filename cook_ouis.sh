#/bin/sh

# OUI.list was borrowed from macchanger
# I decided not to include it in the tree

IN_FILE='OUI.list'
OUT_FILE='oui_list.h'
HEAD='OUI_LIST_H'

echo "#ifndef $HEAD\n#define $HEAD\n"       > $OUT_FILE

echo "unsigned char oui_list[][3] = {"     >> $OUT_FILE

cat $IN_FILE | grep -i "Apple"             >> $OUT_FILE
cat $IN_FILE | grep -i "Atheros"           >> $OUT_FILE
cat $IN_FILE | grep -i "Azurewave"         >> $OUT_FILE
cat $IN_FILE | grep -i "Broadcom"          >> $OUT_FILE
cat $IN_FILE | grep -i "Huawei"            >> $OUT_FILE
cat $IN_FILE | grep -i "intel corporation" >> $OUT_FILE

echo "};\n"                                >> $OUT_FILE

echo "#endif"                              >> $OUT_FILE

sed -i 's/\([0-9a-f][0-9a-f]\)\s\([0-9a-f][0-9a-f]\)\s\([0-9a-f][0-9a-f]\)\s\(\w*\)/    {0x\1, 0x\2, 0x\3}, \/\/ \4/gi' $OUT_FILE

