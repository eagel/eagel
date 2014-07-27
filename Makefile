CXXFLAGS = -std=c++11	-O2 -g -Wall -fmessage-length=0 -Ilib/boost/inc -Iinc

OBJS =		src/main.o\
			src/message/basic_data.o\
			src/message/basic_message.o\
			src/transport/basic_transport.o

TEST_OBJS = tst/main_tests.o\
			tst/message/data_tests.o\
			tst/message/message_tests.o\
			tst/transport/transport_tests.o

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
