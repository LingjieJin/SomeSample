#!/bin/sh
for ((i=0;i<=10;i++))
do
    touch ${i}.jpeg
done

oldsuffix="jpeg"
newsuffix="jpg"
dir=$(eval pwd)

for file in $(ls $dir | grep .${oldsuffix})
    do
        ## 在循环语句中我们使用cut命令将匹配的文件name剪切出来。cut命令从文件的每一行剪切字节、字符和字段并将其送至标准输出。参数-d用于自定义分隔符，默认为制表符,程序中的-d.表示以.作为分隔符；参数-f指定截取显示哪个区域，-f1表示截取第一个区域，也就是文件名的name。
        name=$(ls ${file} | cut -d. -f1) 
        mv $file ${name}.${newsuffix}
    done
echo "change jpeg to jpg successd!"

