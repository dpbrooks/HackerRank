/*
 * Practice defining and catching exceptions using a small
 * computational server
 */
#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) {
		long long A, B;
		cin >> A >> B;

		/* Enter your code here. */
        try {
            int res = Server::compute(A, B);
            cout << res << endl;
        }
        catch (const std::bad_alloc& mem) {
            /* Memory allocation error can occur when
            creating vector<int> v(A, 0) b/c we are dealing
            w/ very large numbers (long long) */
            cout << "Not enough memory" << endl;
        }
        catch (const std::invalid_argument& arg) {
            // Exception to be thrown when an argument is invalid
            cout << "Exception: " << arg.what() << endl;
        }
        catch (const std::exception& e) {
            // Exception to be thrown for any other standard C++ exception
            cout << "Exception: " << e.what() << endl;
        } 
        catch (const int& e) {
            // Any non-standard exception caught by the function
            cout << "Other Exception" << endl;
        }
        

	}
	cout << Server::getLoad() << endl;
	return 0;
}