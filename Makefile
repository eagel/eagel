CXXFLAGS = -std=c++11	-O2 -g -Wall -fmessage-length=0 -Iinc

OBJS =		src/Eagel.o\
			src/Record.o\

TEST_OBJS = tst/main.o\
			tst/Eagel.o\
			tst/Record.o\

TARGET =

TEST_TARGET = dst/tests

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	$(CXX) -o $(TEST_TARGET) $(TEST_OBJS) $(OBJS)

all:	$(TARGET) $(TEST_TARGET)

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)
