#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif

float compute_fx(int functionid, float a, float b, int n, int intensity) {

  float result = 0.0, x = 0.0;
  float multiplier = (b-a)/(float)n;
  int i;


  for (i=0; i<n; i++) {

    x = a + (i + 0.5) * multiplier;
    switch (functionid) {

      case 1:
        result = result + f1(x, intensity)*multiplier;
        break;
      case 2:
        result = result + f2(x, intensity)*multiplier;
        break;
      case 3:
        result = result + f3(x, intensity)*multiplier;
        break;
      case 4:
        result = result + f4(x, intensity)*multiplier;
        break;
      default:

        break;

    }

  }
  return result;

}


int main (int argc, char* argv[]) {

  if (argc < 6) {
    std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity>"<<std::endl;
    return -1;
  }
  int functionid = atoi(argv[1]);
  float a = atof(argv[2]);
  float b = atof(argv[3]);
  int n = atoi(argv[4]);
  int intensity = atoi(argv[5]);

  float result;


  if (functionid < 0 || functionid > 4) {
    std::cerr<<"ERROR: Enter a function id between 1 and 4 "<<std::endl;
  }
  else {

  result = compute_fx (functionid, a, b, n, intensity);

  std::cout <<"The integrated result is "<< result << std::endl;
}


  return 0;
}
