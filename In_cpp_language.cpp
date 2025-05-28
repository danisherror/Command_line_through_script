#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

using namespace std;

string execCommand(const char* cmd) {
    array<char, 256> buffer;
    string result;

    // Open pipe to execute the command
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw runtime_error("popen() failed!");
    }

    // Read output into result string
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    return result;
}

int main() {
    try {
        string currentDir = execCommand("pwd");
        string fileList = execCommand("ls");

        cout << "Current directory:\n" << currentDir << endl;
        cout << "File list:\n" << fileList << endl;
    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }
}
