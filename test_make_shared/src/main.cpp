#include <cstdio>
#include <memory>

class Test : public std::enable_shared_from_this<Test> {
public:
  Test() noexcept {
    printf("Test created\n");
  }
  ~Test() noexcept {}
  void foo() { shared_from_this(); };
};

int main(int argc, const char *argv[]) {
  auto t = std::make_shared<Test>();
  t->foo();

  return 0;
}