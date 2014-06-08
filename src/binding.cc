
#include <cstdlib>
#include <iostream>
#include <node.h>
#include <sstream>
#include <v8.h>


using namespace node;
using namespace std;
using namespace v8;


// Source: http://stackoverflow.com/questions/8496182/calculating-powa-b-mod-n
template <typename T>
T MathModExp(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;

  while (exp > 0) {
    if (exp & 1) {
      result = (result * base) % modulus;
    }

    base = (base * base) % modulus;
    exp >>= 1;
  }

  return result;
}


uint64_t Str2UInt64(const Local<Value>& str) {  
  String::Utf8Value utf8(str->ToString());

  stringstream ss;
  char* ps = *utf8;
  if (utf8.length() > 2 && ps[0] == '0' && ps[1] == 'x') {
    ss << hex << (ps + 2);
  } else {
    ss << ps << endl;
  }

  uint64_t n;
  ss >> n;

  return n;
}


string UInt642Str(const uint64_t value) {
  stringstream ss;
  ss << hex << value;
  return ss.str();
}


Handle<Value> ModExp(const Arguments& args) {
  HandleScope scope;

  if (args.Length() != 3) {
    return ThrowException(Exception::Error(String::New("modexp requires 3 arguments")));
  }

  for (unsigned i = 0; i < 3; i++) {
    if (!args[i]->IsString()) {
      return ThrowException(Exception::Error(String::New("all modexp arguments should be strings")));
    }
  }

  uint64_t base = Str2UInt64(args[0]);
  uint64_t exp = Str2UInt64(args[1]);
  uint64_t mod = Str2UInt64(args[2]);

  uint64_t result = MathModExp(base, exp, mod);

  const char* ret = UInt642Str(result).c_str();
  return scope.Close(String::New(ret));
}


void init(Handle<Object> target) {
  target->Set(String::NewSymbol("modexp"), FunctionTemplate::New(ModExp)->GetFunction());
}


NODE_MODULE(binding, init);

