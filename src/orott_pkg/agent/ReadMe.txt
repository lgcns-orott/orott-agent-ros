=========================================================================
  Compile
=========================================================================
  cd base
  make
  cd ..
  make

=========================================================================
  Run
=========================================================================
  ./rspAgent

=========================================================================
  About a base directory
=========================================================================
  It is the base library of Linux C version of the RSP Agent.
  librspagent.so is created in the base directory when It is built.

  If you add new job. You should modify JobQueue/JobScheduler.c and include/JobScheduler.h
  and Add a <new job>.c to a Jobs directory and Add a <new job>.h to an include/job directory

=========================================================================
  Port to other systems or real robots
=========================================================================
  1. Compile libraries in external/src directory for other system.
  2. modify RASysInfo in a src directory.
  3. If you want to use other secure library, not libopenssl and libcrypto. modify a RASecure.c in src direcotry.
  4. If you want to use other Http library, not curl. modify a RAHttpsConn.c in src directory.
  5. If you want to use other MQTT library, not paho. modify a RAMqttConn.c in src direcotry.
  6. If you want to apply thread functions to the priority queue. modify a JobHandler.c in base/JobQueue directory.
  7. If you want to apply common oneM2M module. modify NotifyProc.c and Reporter.c in base/JObs directory.

