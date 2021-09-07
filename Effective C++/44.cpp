//条款44：将与参数无关的代码抽离templates
/*
总结
1.Templates 生成多个 classes 和多个函数，所以任何template 代码都不该与某个造成膨胀的template参数产生相依关系。
2.因非类型模板参数 ( non-type template parameters) 而造成的代码膨胀，往往可消除，做法是以函数参数或class 成员变量替换 template 参数。
3.因类型参数 ( type parameters) 而造成的代码膨胀，往往可降低，做法是让带有完全相同二进制表述 ( binary representations ) 的具现类型 ( instantiation types) 共享实现码。
*/
