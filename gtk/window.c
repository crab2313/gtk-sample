#include <gtk/gtk.h> /* gtk+ library 的头文件，*/
		     /* 和QT不一样，gtk+只需要这一个头文件 */

int main(int argc, char **argv)
{
	GtkWidget *window; /* gtk 使用一个指针来代表和操作一个对象 */

	gtk_init(&argc, &argv); /**
				 * 这个是初始化 gtk+， 
				 * 基本上是 gobject 和 event loop的初始化， 
				 * 必须要带上 
				 */

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL); /* 初始化一个window控件 */
	
	gtk_window_set_title(GTK_WINDOW(window), "Window");
	/* 这行要讲的多点， 从这个小程序就可以看见gtk的命名规则， 
	 * gtk的函数全部以gtk开头, 中间用下划线隔开， 这里第二个window， 
	 * 代表 这个函数是用于操作window的， 后面才是真正的命名， 
	 * 可以理解成 gtk.window.set_title() 这里就是OO了
	 * 后面这个GTK_WINDOW是一个macro， 用于类型转换， 
	 * gobject实现的继承机制需要手动转换因为 window本身是一个 
	 * GtkWidget 的指针， 所以要转换成 GtkWindow 的指针
	 */
	
	g_signal_connect(G_OBJECT(window), "destroy", 
			G_CALLBACK(gtk_main_quit), NULL);
	/* 这个函数用于将一个对象的信号与回调关联起来 */
	
	gtk_widget_show(window); /* 显示这个控件， 控件初始化以后默认不显示的 */
	gtk_main(); /* 开始gtk的event loop， 也就是开始这个gtk界面 */
	return 0;
}
