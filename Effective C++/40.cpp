//明智而审慎地使用多重继承

/*
若File有一个成员变量 filename,则根据两条路径，
IOFile有2个filename是否有违常识？（使用InputFile::来解决）
解决方案使用virtual继承
*/

class File {};
class InputFile:virtual public File{};
class OutputFile:virtual public File{};
class IOFile :public InputFile, public OutputFile {};

/*
总结
1.多重继承比单一继承复杂。它可能导致新的歧义性，以及对virtual继承的需要。
2.virtual继承会增加大小、速度、初始化（及赋值）复杂度等等成本。如果virtual base classes 不带任何数据，将是最具实用价值的情况。
3.多重继承的确有正当用途。其中一个情节涉及 “ public  继承某个 Interface  class"
和 “ private  继承某个协助实现的class "  的两相组合。
*/