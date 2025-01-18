#include "./megaphone.hpp"

void print_arg_lower_to_upper(char *str)
{
  std::string s;

  for (int i = 0; str[i]; i++) {
    s += toupper(str[i]);
  }
  std::cout << s << std::flush;
}

int main(int argc, char *argv[])
{
  int i;

  i = 1;
  std::string s;
  s = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  if (argc == 1) {
    std::cout << s << std::endl;
    return (0);
  }
  for (int i = 1; argv[i]; i++) {
    print_arg_lower_to_upper(argv[i]);
    if(argv[i+1])
      std::cout << " " << std::flush;
    else
      std::cout << "\n" << std::flush;
  }
  return (0);
}
