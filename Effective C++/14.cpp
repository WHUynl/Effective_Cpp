//在资源管理类中小心copying行为

/*
总结
1.复制 RAII对象必须一并复制它所管理的资源，所以资源的copying行为决定RAII对象的copying行为。
2.普遍而常见的 RAII class copying 行为是：抑制copying、施行引用计数法
(reference counting ) 。不过其他行为也都可能被实现。
*/