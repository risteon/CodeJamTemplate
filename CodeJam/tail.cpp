//#region main
namespace task{
long long unsigned T;
void init();
void readInput();
void calcFunction();
}

struct IO {
  std::streambuf* coutbuf;
  std::streambuf* cinbuf;
  std::ifstream in;
  std::ofstream out;

  IO() {
    coutbuf = cinbuf = nullptr;
  }
};

IO io_from_file(int argc, char* argv[])
{
  IO io{};

  if (argc < 2)
  {
    return io;
  }

  struct stat buffer;
  if (stat (argv[1], &buffer) != 0)
  {
    std::cerr <<"Make sure input exists: " <<argv[1] <<std::endl;
    return io;
  }
  io.coutbuf = nullptr;
  io.cinbuf = nullptr;
  io.in.open(argv[1]);
  io.cinbuf = std::cin.rdbuf(io.in.rdbuf());
  if (argc > 2)     //< write to output file
  {
    io.out.open(argv[2]);
    io.coutbuf = std::cout.rdbuf(io.out.rdbuf());
  }
  return io;
}

void cleanup_io(std::streambuf* coutbuf, std::streambuf* cinbuf)
{
  if (coutbuf)
    std::cout.rdbuf(coutbuf);
  if (cinbuf)
    std::cin.rdbuf(cinbuf);
}

COMM_TYPE result;
int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);  // don't use scanf when sync turned off -> https://www.geeksforgeeks.org/cincout-vs-scanfprintf/
    std::cin.tie(nullptr); std::cout.tie(nullptr);

#ifdef LOCAL
  const IO io = io_from_file(argc, argv);
#endif /*LOCAL*/

    std::cerr << std::setprecision(4);
    std::cout << std::setprecision(10);
    task::init();
    for(long long unsigned test=1; test<=task::T; ++test){
        llog();
        llog();
        llog();
        llog();
        llog("################################################");
        llog("################################################");
        llog("################################################");
        llog("################", test, "################");
        llog("################################################");
        llog("################################################");
        llog("################################################");
        llog();
        llog("============      reading input     ============");
        start_timer();
        task::readInput();
        stop_timer();
        llog("-----------", get_time(), "secs -----------");
        llog();
        llog("============    doing computation   ============");
        start_timer();
        task::calcFunction();
        stop_timer();
        llog("-----------", get_time(), "secs -----------");
        llog();
#ifndef IA_MODE
        //write output
        std::cout << "Case #" << test << ": ";
#ifndef DEFAULT_VAL_MODE
        std::cout << result << std::endl;
#else
        if(DEFAULT_VAL_TRIGGER){
            llog("default val triggered");
            std::cout << DEFAULT_VAL << std::endl;
        }
        else{
            llog("default val NOT triggered");
            std::cout << result << std::endl;
        }
#endif /*DEFAULT_VAL_MODE*/
#endif /*IA_MODE*/
    }

#ifdef LOCAL
  cleanup_io(io.coutbuf, io.cinbuf);
#endif /*LOCAL*/

    return 0;
}
//#endregion main

//#endregion template code

namespace task {

using namespace std;

void init(){
    cin >> T;
}

void readInput(){
}

// write to COMM_TYPE result
void calcFunction() {
}

} // namespace task
