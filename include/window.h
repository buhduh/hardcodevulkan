#ifndef LINUX_WINDOW
#define LINUX_WINDOW
/*
	I understand this is probably freaking awful, but
	you gotta start somewhere....
*/
class Window {
	public: 
	virtual void initWindow() = 0;
	//native window handlers on "x" button push etc
	virtual bool shouldClose() = 0;
	//native window destroy method;
	virtual void destroy() = 0;
};
#endif
