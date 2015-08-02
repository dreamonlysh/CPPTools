## 概述
>   基础章节主要介绍了doxygen的基本语法，用于注释类、成员、函数等，由此可以生成含有注释的文档。但在拥有基本注释内容的基础上，面对大量注释，希望可以合理的分类以及布局，即本文将介绍的doxygen分组方法。
## 模块(modules)
>   模块的划分会显示在CHM文件中的目录树上，每个模块将单独作为一页显示。这里将着重介绍@defgroup、@addtogroup、@{...@}、@ingroup
### defgroup
>   模块定义的唯一方式，可以是纯定义，也可以定义时初始化模块内容：

1.纯定义
```
/**
 * @defgroup [gTag] [gName]
 * This is brief.
 * This is detail.
 */
```
2.定义+初始化
```
/**
 * @defgroup [gTag] [gName]
 * This is brief.
 * This is detail.
 * @{
 */
...
/** @} */
```
>   1.模块的定义语句包含了三部分CMD+TAG+NAME，如上所示：@defgroup为CMD代表定义一个模块；[gTag]为TAG信息，可理解为索引，其他命令将通过它来定位到本模块；[gName]为NAME信息，真实显示到注释文件中的模块名。
>   2.这里涉及到了@{...@}，这类似于类和函数等的{...}，表示其中大括号中包含的内容属于当前模块。
>   3.模块可以嵌套（subgroup）
### addtogroup
>   如其名，将某段内容添加到模块：

```
/**
 * @addtogroup [gTag]
 * This is detail.
 * @{
 */
...
/** @} */
```
>   由以上的格式可见，其与定义+初始化的defgroup比较类似。其中[gTag]为之前定义的group索引，但不用添加模块名；描述信息中仅有detail信息，用以补充group的detail信息。
### ingroup
>   ingroup功能与@{...@}基本相同，不同点在于ingroup拥有更高的优先级。在defgroup或addtogroup中已进行分组的内容会因为@ingroup命令而重新确定归属。

1.示例：将某块代码添加到组
```
/**
 * @ingroup [gTag]
 * This is brief.
 */
class tClass {}
```
2.示例：将某组添加为子组
```
/**
 * @defgroup [gTagSub] [gNameSub]
 * @ingroup [gTag]
 * This is brief.
 */
```
3.示例：将文件添加到组
```
/** @file
 *  @ingroup group3
 *  This is brief.
 */
```
4.示例：将class/file/namespace添加到多个组
```
/**
 * @ingroup group1 group2 group3 group4
 * This is brief.
 */
```
### weakgroup
>   功能与addtogroup完全相同，不同的是优先级非常低，在有冲突的情形下，将会被惰性加载。该功能可用于在hpp文件中使用高优先级的分组方法、cpp中使用weakgroup低优先级的分组方法，那么cpp就无需完全复制hpp中的分组方式，从而避免冲突。
## 成员分组(member group)
>   模块为分页显示，成员分组功能则是一个class或file内部的分组(个人理解为页内分组，其中成员分组又针对class和file级别做了分组显示。)。若未指定成员分组，doxygen将执行默认分组，例如分为宏定义、函数、变量等。以下将重点介绍分组方法@name
### name
>   成员分组也用到@{...@}，用于将包含的内容指定到组。若未指定@name，该分组在doxygen的默认分组下，但会以空行隔开放置最后。自定义的组名的分组示例如下：

```
/** 
 * A class. Details
 */
class Test
{
public:
    /**
     * @{
     */
    void func1InGroup1();
    /** @} */

    /**
     * @name MyGroup
     * This is brief.
     * This is detail.
     * @{
     */
    void func2InGroup1();
    /** @} */

    void ungroupedFunction();
};
```
>   如上，在doxygen的class Test页内，我们将期望看到MyGroup分组。然而可以发现该分组为Public Member Functions分组的一个子组。
### 禁止分组为子组
>   class或file添加@nosubgrouping命令

```
/** 
 * @nosubgrouping
 * A class. Details
 */
class Test
{
}
```
>   添加该命令后doxygen默认分组下将再无子组，未命名的分组将失效，已命名的分组将变为与默认分组平级的组。
### 注意
>   参考[Member Groups][1]中的示例，其中有几项注意点：
>   1.无nosubgrouping：成员分组中跨类别(public/protected/private/static等)情形下，将自动将命名的组与默认组平级（莫误以为在class的实现上添加的分组就一定会平级）。
>   2.有nosubgrouping：未命名的分组表现有些怪异，当所有成员分组都在class内部定义时，未命名分组中内容将填充到默认分组下；若分组定义不在class的{}内部(例：包含方法的实现Test::func())时，未命名分组将追加到class外部定义分组的后面。
>   3.分组name相同时，将显示在同一个组里；分组不能嵌套
### 规范(私用)
>   1.禁用所有子组，在有成员分组功能的class或类中必须添加@nosubgrouping
>   2.禁用不带name的未命名分组
>   3.class的所有分组定义必须包含在{}范围内，禁止在class外的实现上定义分组


[1]:http://www.stack.nl/~dimitri/doxygen/manual/grouping.html