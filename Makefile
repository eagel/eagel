CXXFLAGS = -std=c++11	-O2 -g -Wall -fmessage-length=0 -Ilib/boost/inc -Iinc

OBJS =		src/main.o\
			src/data/basic_data.o\
			src/data/reference.o\
			src/data/list.o\
			src/data/map.o

TEST_OBJS = tst/main_tests.o\
			tst/data/data_tests.o

LIBS =		lib/boost/lib/libboost_system.a

TEST_LIBS = lib/boost/lib/libboost_unit_test_framework.a

TARGET =

TEST_TARGET = dst/tests

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	$(CXX) -o $(TEST_TARGET) $(TEST_OBJS) $(OBJS) $(LIBS) $(TEST_LIBS)

all:	$(TARGET) $(TEST_TARGET)

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)
