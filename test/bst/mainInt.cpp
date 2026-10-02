/**
 * This program takes two arguments: an input file and an output
 * file. If no arguments are given, then the program will use stdin
 * and stdout instead. The commands provided are for ease of testing
 * and for ease of grading.
 *
 * Commands:
 * INSERT <value>
 *   Takes an integer value and inserts it into the BST.
 * FIND <value>
 *   Attempts to find the element value in the BST and sets the
 *   iterator to the location of the element found.
 * NEXT
 *   Advances the iterator and prints the next value in the tree.
 * SIZE
 *   Reports the size of the BST.
 * HEIGHT
 *   Reports the height of the BST.
 * EMPTY
 *   Reports whether the tree is an empty BST.
 * BEGIN
 *   Sets the iterator to the beginning of the tree.
 * PRINT
 *   Prints the internal structure of the BST.
 * BALANCE
 *   Uses the copy constructor to balance the tree.
 * DELETE <value>
 *   Removes a certain value from the tree.
 * EXIT
 *   Exits the program and frees any memory used.
 *
 * Usage: ./mainInt.cpp.executable <input filename> <output filename>
 *
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "BST.hpp"

#define NUM_ARGS_FOR_STD_INOUT 1
#define NUM_ARGS_FOR_FILE_INOUT 3
#define INPUT_FILE_INDEX 1
#define OUTPUT_FILE_INDEX 2

using namespace std;

int main(int argc, char* argv[]) {
    // Polymorphism in C++ requires us to have pointers to the objects,
    // at which point we can call their virtual methods with runtime
    // types
    istream* in;
    ostream* out;
    if (argc == NUM_ARGS_FOR_STD_INOUT) {
        // Input and output come from the command line
        in = &cin;
        out = &cout;
    } else if (argc == NUM_ARGS_FOR_FILE_INOUT) {
        // ifstream and ofstream stand for input file stream
        // and output file stream -- here we are taking input
        // from a file and writing to another file
        in = new ifstream(argv[INPUT_FILE_INDEX]);
        if (!in->good()) {
            cerr << "Failed to open file " << argv[INPUT_FILE_INDEX] << endl;
            return 1;
        }

        out = new ofstream(argv[OUTPUT_FILE_INDEX]);
        if (!out->good()) {
            cerr << "Failed to open file " << argv[OUTPUT_FILE_INDEX] << endl;
            return 1;
        }
    } else {
        cerr << "Invalid number of arguments: " << argc << endl;
        return 1;
    }

    BST<int>* bst = new BST<int>();
    // Allocate a buffer into which we can store
    // the iterator
    BST<int>::iterator it = bst->end();

    *out << "GREETINGS! TYPE COMMANDS TO VISUALIZE YOUR BST." << endl;

    // Without checking for eof() it's possible to end up in
    // a situation where we loop forever on a file that didn't
    // terminate with EXIT
    while (!in->eof()) {
        string line;

        getline(*in, line);
        stringstream sstream(line);

        string command;
        sstream >> command;
        if (command == "INSERT") {
            int val;
            sstream >> val;

            bool success = bst->insert(val);
            if (success) {
                *out << "Insert: Successfully inserted value " << val << endl;
            } else {
                *out << "Insert: Failed to insert value " << val << endl;
            }

        } else if (command == "FIND") {
            int val;
            sstream >> val;

            it = bst->find(val);
            if (it == bst->end()) {
                *out << "Find: Value " << val << " not found!" << endl;
            } else {
                *out << "Find: Value " << val << " found!" << endl;
            }

        } else if (command == "NEXT") {
            if (it == bst->end()) {
                *out << "Iterator: Cannot traverse to next; hit end of tree"
                     << endl;
            } else {
                it++;
                if (it == bst->end()) {
                    *out << "Iterator: Hit end of tree" << endl;
                } else {
                    *out << "Iterator: " << *it << endl;
                }
            }

        } else if (command == "SIZE") {
            *out << "Size: " << bst->size() << endl;
        } else if (command == "HEIGHT") {
            *out << "Height: " << bst->height() << endl;
        } else if (command == "EMPTY") {
            *out << "Empty: " << (bst->empty() ? "true" : "false") << endl;
        } else if (command == "BEGIN") {
            it = bst->begin();
            if (it == bst->end()) {
                *out << "Iterator: Hit end of tree" << endl;
            } else {
                *out << "Iterator: " << *it << endl;
            }
        } else if (command == "PRINT") {
            *out << "Printing BST Structure" << endl;
            bst->print(out);
        } else if (command == "BALANCE") {
            // Since we're getting rid of the old BST here, we
            // need to delete it in order to ensure that we don't
            // have a memory leak.
            BST<int>* newBst = new BST<int>(*bst);
            delete bst;
            bst = newBst;
            // The iterator uses a pointer into the old BST's structure
            // so we want to prevent the user from accessing that memory
            // again
            it = bst->end();
            *out << "BST balanced" << endl;
        } else if (command == "EXIT") {
            break;
        } else if (command == "DELETE") {
            int val;
            sstream >> val;

            bool success = bst->deleteNode(val);
            if (success) {
                *out << "Delete: Successfully deleted value " << val << endl;
            } else {
                *out << "Delete: Failed to delete value " << val << endl;
            }
        }
    }

    if (argc == NUM_ARGS_FOR_FILE_INOUT) {
        ((ifstream*)in)->close();
        delete in;
        ((ofstream*)out)->close();
        delete out;
    }

    delete bst;
    return 0;
}