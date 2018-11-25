首先这个程序会复杂是因为我想要它能处理上G的文件，但是最后费了很多时间是因为一些不好的习惯造成的。
这个程序真真切切的让我知道了一次性写好程序的重要性，以及无论什么程序，都要做整体设计。

我在调试这个huffman编码时花了很多时间，主要是我想尝试一下什么是面向内存编程，故花了很多力气对文件流，内存情况进行调试，实验。

以下是HUFFMAN压缩程序的总结：

# 存储结构与程序关系
**搞清楚存储方式是big-endian 还是small-endian，以及是否你的程序内部逻辑需要用到这个知识。**

在你面向内存编程，其实无论是big-endian 还是small-endian，也就是要把值存储到内存段上的时候，其实都是顺着存储的。这里不会涉及到申请变量时栈向上写，普通内存区向下写的问题。

# 先对程序结构进行梳理，再写程序

编程中最耽误时间的部分应该就是DEBUG了，想要又快又好的写完除了不犯小错误外，我觉得还可以从以下几点入手：
1. 写之前对于基本的逻辑结构有个大致的数，这点大多数人都能做到。
2. 写之中遇到复杂的逻辑情况应该先把逻辑梳理清楚，这点大多数人能做到。
3. 写的时候要记忆前面部分的关键细节，比如如果模块之间有交互，前面的储存方式就要记忆下来，这点是我这次没有做好的。
4. 还有一类常见错误是由于粘贴复制代码导致的代码名不对，功能模块忘记改。解决这类错误最好的办法就是在粘贴前把要更改的功能写下来，粘贴后逐一审查代码，看需要改的地方是不是都改了。
5. 未知函数的使用还是要谨慎一些。（仅适用于新手）
6. 复杂算法最好能脑子中过一遍所有细节流程，（一般来说就是开始和结束），千万要过一遍，不能想当然的就直接写出来！！！靠调试会很慢很不靠谱，算法中的控制逻辑是最需要注意的地方。
***这次在做HUFFMAN DECODING的时候一开始就想当然以为访问树就是先读出buf[i]来判断是往哪边走，然后更新树。因为没有考虑末端情况，既叶节点访问后要多停留一次而导致错误。***

# DEBUG方式总结
1. 内存查看，不再赘述。
2. 文件流查看，一般就是看文件流指针，C语音里面可以使用```_ftelli64(stream_wr);```来查看。
3. 错误处理类[@ERR](http://wiki.jikexueyuan.com/project/c/c-error-handling.html).