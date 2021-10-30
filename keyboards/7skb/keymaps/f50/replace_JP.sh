#!/bin/bash
cd `dirname $0`

# 日本語キー名をKC形式に置換する
# keymap_jp.hにある#defineを使う

list=replace_list.sed

file=7skb_via.json
backup=7skb_via.bk.json
output=7skb_via.out.json

# 置換コマンドのリストを作成する
# keymap_jp.hからだと置換が不可能なキーコードだけ先に処理してしまう
echo "s/JP_UNDS/S(KC_RO)/g" > ${list}_tmp
echo "s/JP_BSLS/KC_RO/g" >> ${list}_tmp
echo "s/JP_PIPE/S(KC_JYEN)/g" >> ${list}_tmp

# わかりずらいが
# #define JP_1    KC_1    // 1
# を s/"JP_1"/"KC_1"/g という文字列に変換する
# "" で囲っておかないと JP_TILD は先にJP_TがKC_Tに置き換えられてしまってKC_TILDになってしまう
cat keymap_jp.h | grep define | awk '{ print "s/\""$2"\"/\""$3"\"/g" }' >> ${list}_tmp
# 上だけだと()に囲まれた文字列を置換できないので さらに追記する
cat keymap_jp.h | grep define | awk '{ print "s/[(]"$2"[)]/("$3")/g" }' >> ${list}_tmp

# リスト内の ( ) をエスケープ
cat ${list}_tmp | sed -e 's/[(]/\\(/g' -e 's/[)]/\\)/g' > $list

# 一応バックアップ
cp $file $backup
# 置換 数回実行して置換後の文字列も置換する
sed -f $list $file > $output
sed -f $list $output > $output.1
sed -f $list $output.1 > $output
rm $output.1 ${list}_tmp

# 完了

