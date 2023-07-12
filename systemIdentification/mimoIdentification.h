#include <vector>

class MimoIdentification{
  private:

  public:
    MimoIdentification();
    ~MimoIdentification();

    std::vector<float> identifyMimo(std::vector<float>inputs);
};
