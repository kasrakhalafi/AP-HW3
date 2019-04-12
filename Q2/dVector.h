class dVector{
 public:
  void push_back(int);
  void pop_back();
  void size();
  int capacity();
  int cnt=1;
  bool operator<(const dVector&) const;
  bool operator==(const dVector&) const;
  int operator*(const dVector&) const;
  dVector operator=(const dVector&);
  dVector() = default;
  ~dVector();
  dVector(const dVector& );
  dVector(dVector &&);
  dVector operator+(const dVector&);
  void show();
  int* array;

};
