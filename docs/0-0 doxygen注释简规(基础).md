## 概述
>   本文档主要抽取了doxygen中的一种注释方式，用于C++编码的自动文档生成，避免代码中多种风格代码注释的混用。同时考虑到会有JAVA方面的需求，所以本文的内容将会更加偏向于JavaDoc。*主要用于规范自己开发的注释风格，当前从最简单的整理，后续涉及到再补充。*
## 注释风格
```
/** 
 * ...Details of comment...
 */
```
## 概要
>   概要信息为注释中的第一段语句，第一个**.**出现的位置为brief结束，注意**.**后方添加一个空格。接着的为详细描述信息以及其他信息。
>   *注：JAVADOC_AUTOBRIEF*选项设为*YES*

```
/**
 * Start a brief. 
 * Start descriptions.
 */
```
## 代码后注释
>   针对文件、结构体、联合、类、枚举等的成员注释不在之前，而是成员之后，需要使用代码后注释。

```
enum {
    NUM_ZERO, ///< 这是0
    NUM_ONE   ///< 这是1
}
```
## 注释-file
```
/**
 * @file    [file name]
 * @author  [author]
 * @date    [finish date]
 * @brief   [brief]
 */
```
## 注释-const/typedef/#define
```
const int EXAMPLE = 0;  ///< This is constant 0
```
>   若描述信息较长，可以考虑使用JavaDoc中注释在语句前的风格。
## 注释-enum
```
/**
 * This is brief.
 * This is detail.
 */
enum example {
    EX_1,   ///< This the first
    EX_2    ///< This the second
};
```
>   若枚举只有brief信息，且较见简单，可/** brief */
## 注释-class/struct
```
/**
 * This is brief.
 * This is detail.
 */
class example
{
public:
    example() {}

    ~example() {}

private:
    int mem1_;  ///< This is member 1
    int mem2_;  ///< This is member 2
};
```
## 注释-interface/method
>   函数注释相对其他注释略微复杂，因为函数注释中的参数未使用后注释注释形参而是用*@param*形式。另外增加了return、attention以及example三项内容。详情见下：

```
/**
 * This is brief.
 * This is details.
 * @param [in]      str1    In param
 * @param [in, out] str2    In and out param
 * @return                  Return meanings
 * @attention   This can be used in some conditon.
 * @par examples:
 * @code
 *      Here is an example to use funcToDoc.
 * @endcode
 */
bool funcToDoc(const std::string& str1, std::string& out1)
{

}
```
>   1.param
>   >   该参数分为三段[in]、[out]、[in, out]代表了三种数据类型；str1代表了形参；之后为每个参数的描述
>  
>   2.return
>   >   解释返回值的含义
>  
>   3.attention
>   >   用于额外的提示信息，需要调用者特别注意的店
>   
>   4.examples
>   >   示例为自定义的字段，从par到endcode，对于接口使用的示例

## 其他
>   1.注释信息可以使用\n换行
>   2.doxygen尚具有很多字段，可参见[Special commands][1]
>   3.param/return等多次调用时，只会产生一个条目，但每条记录将是一行


[1]:http://www.stack.nl/~dimitri/doxygen/manual/commands.html