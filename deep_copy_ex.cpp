#include <iostream>

#include <string>  // for strings 
#include <cstring> // for things like strcpy, strlen, strcmp, .c_str(),  etc.
//#include <sstream> // makes strings behave like char arrays, so they can be deep copied

using namespace std;

//Here is an example of a deep copy
//
int main(){

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//char * dynamic_array = "a_dynamic_char_array";
	//notice the char * dynamic_array throws an error if uncommented, 
	//below are three work arounds, they are deep copies
	
	cout << "string literal \"a_string_literal\" being copied to a dynamic char array\n";
	char * dynamic_array = new char[strlen("a_string_literal") + 1]; //the +1 accounts for terminating character
	strcpy(dynamic_array, "a_string_literal");
	cout << "char * dynamic_array = " << "\"" << dynamic_array << "\"" << endl;

	cout << "deleting dynamic char array" << endl << endl;
	delete [] dynamic_array; //delete the dynamic array so we can use it again

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 	//to deep copy from a static array is essentially the same	
	char static_array[] = "a_static_char_array";
	cout << "static char array \"" << static_array << "\" being copied to the same dynamic char array\n";
	dynamic_array = new char[strlen(static_array) + 1]; //the +1 accounts for terminating character
	strcpy(dynamic_array, static_array);
	cout << "now char * dynamic_array = " << "\"" << dynamic_array << "\"" << endl;

	cout << "deleting dynamic char array (again)" << endl << endl;
	delete [] dynamic_array; //delete the dynamic array so we can use it again

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//to deep copy from a string is just a tiny bit different, 
	//we need to add the .c_str() function. \" .str() \" is part of the cstring library
	string my_string = "a_string";
	cout << "string variable \"" << my_string << "\" being copied to the same dynamic char array\n";
	dynamic_array = new char[strlen(my_string.c_str()) + 1]; //the +1 accounts for terminating character
	strcpy(dynamic_array, my_string.c_str());
	cout << "now char * dynamic_array = " << "\"" << dynamic_array << "\"" << endl;

	cout << "deleting dynamic char array (again)" << endl << endl;
	delete [] dynamic_array; //delete the dynamic array so we can use it again
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}
