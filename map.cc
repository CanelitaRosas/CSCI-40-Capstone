#include <vector>
#include "/public/colors.h"

using namespace std;

vector<string> world_map_test = {
	"********************",
	"*     +-------+    *",
	"*     |   *   |    *",
	"*     |  /|\\  |    *",
	"*     |  / \\  |    *",
	"*     +-------+    *",
	"********************"
};



int main() {
	for (int i = 0; i < world_map_test.size(); i++) {
		cout << world_map_test.at(i) << endl;
	}

	return 0;
}
