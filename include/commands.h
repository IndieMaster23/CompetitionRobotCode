#ifndef   COMMANDS_CLASS_H
#define   COMMANDS_CLASS_H

class Commands {
  private:
    static bool arcadeControlMode;
    static int count;
    static long t;
    static std::string ctrlSeq;

    void static buttonPressed(std::string s);

    void static leftButtonPressed(void);
    void static rightButtonPressed(void);
    void static upButtonPressed(void);
    void static downButtonPressed(void);
    void static aButtonPressed(void);
    void static bButtonPressed(void);
    void static xButtonPressed(void) ;
    void static yButtonPressed(void);

  public:
    void init(vex::controller);
    bool isArcadeControlMode(void);
};

#endif  // COMMANDS_CLASS_H
