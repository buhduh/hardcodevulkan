#ifndef UTILS_H
#define UTILS_H
/*
	As this is my first (real) cpp project I don't have a standard
	utils package.  It's fine here for now, but consider a project
	agnostic solution in the future.
*/

#include <string>
#include <string.h>

namespace utils {
	typedef std::string str;
	inline bool hasPrefix(str s, str pre) {
		if(s.empty() || pre.empty()) return false;
		return s.find(pre) == 0;
	}
	inline bool hasSuffix(str s, str suf) {
		if(s.empty() || suf.empty()) return false;
		return s.rfind(suf) == s.size() - suf.size();
	}
	//Not platform safe, linux only
	inline std::string readErrno(int foo) {
		char buf[256];
		strerror_r(foo, buf, 256);
		return std::string(buf);
	}
};
#endif
