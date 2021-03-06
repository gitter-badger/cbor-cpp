/*
   Copyright 2014-2015 Stanislav Ovsyannikov

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

	   Unless required by applicable law or agreed to in writing, software
	   distributed under the License is distributed on an "AS IS" BASIS,
	   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	   See the License for the specific language governing permissions and
	   limitations under the License.
*/
#include "Cbor.h"
#include <climits>

void test1() {
    CborDynamicOutput output;
    CborWriter writer(output);

    writer.writeArray(10000 * 3);
    for(int i = 0; i < 10000; i++) {
        writer.writeInt(123);
        writer.writeInt(12);
        writer.writeString("hello", 5);
    }

    CborInput input(output.getData(), output.getSize());
    CborDebugListener listener;
    CborReader reader(input);
    reader.SetListener(listener);
    reader.Run();
}

void test2() {
    CborDynamicOutput output;
    CborWriter writer(output);

    writer.writeInt(INT_MIN + 1);
    writer.writeInt(INT_MIN);
    writer.writeInt((long long)INT_MIN - 1);

    writer.writeInt(INT_MAX - 1);
    writer.writeInt(INT_MAX);
    writer.writeInt((long long) INT_MAX + 1);

    CborInput input(output.getData(), output.getSize());
    CborDebugListener listener;
    CborReader reader(input);
    reader.SetListener(listener);
    reader.Run();
}

int main(int argc, char **argv) {
    test1();

    return 0;
}