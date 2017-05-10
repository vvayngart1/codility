#include "stdafx.h"

#include <iostream>
#include <string>
#include <stdexcept>

/*
Path path("/a/b/c/d");
path.cd("../x");
std::cout << path.getPath();
should display '/a/b/c/x'.
*/

class Path
{
public:
	Path(std::string path)
	{
		currentPath = path;
	}

	std::string getPath() const
	{
		return currentPath;
	}

	/*
	Path path("/a/b/c/d");
	path.cd("../x");
	std::cout << path.getPath();
	should display '/a/b/c/x'.
	*/
	void cd(std::string newPath)
	{
		if ('/' == newPath[0]) {
			currentPath = newPath;
			return;
		}

		char curr = 0;
		char prev = 0;

		int prevIndex = 0;
		int index = 0;
		while (true) {
			index = newPath.find_first_of('/', prevIndex);
			if (std::string::npos == index) {
				std::string subPath = newPath.substr(prevIndex);
				if (subPath == "..") {
					if (currentPath.length() > 1) {
						int revIndex = currentPath.find_last_of('/');
						if (std::string::npos != revIndex) {
							currentPath.erase(revIndex, currentPath.length() - revIndex);
						}
					}
				} else {
					currentPath += "/" + subPath;
				}
				return;
			}

			std::string subPath = newPath.substr(prevIndex, index-prevIndex);
			prevIndex = index + 1;
			if (subPath == "..") {
				if (currentPath.length() > 1) {
					int revIndex = currentPath.find_last_of('/');
					if (std::string::npos != revIndex) {
						if (0 == revIndex)
							currentPath = "/";
						else
							currentPath.erase(revIndex, currentPath.length() - revIndex);
					}
				}
			} else {
				currentPath += "/" + subPath;
			}
		}
	}

private:
	std::string currentPath;
};

#ifndef RunTests
int main()
{
	Path path("/a/b/c/d");
	path.cd("../x");
	std::cout << path.getPath() << "\n";

	path.cd("/");
	std::cout << path.getPath() << "\n";

	path.cd("/a/b/c/d");
	std::cout << path.getPath() << "\n";

	path.cd("/e/d/f/g");
	std::cout << path.getPath() << "\n";

	path.cd("../../h/j");
	std::cout << path.getPath() << "\n";

	path.cd("..");
	std::cout << path.getPath() << "\n";

	path.cd("../../../../..");
	std::cout << path.getPath() << "\n";
}
#endif
