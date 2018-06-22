#ifndef _DoubleBuffer_h_
#define _DoubleBuffer_h_

template<typename T>
class DoubleBuffer
{
public:
    DoubleBuffer()
            : reader_using_inst0_(true)
    {
    }

    virtual ~DoubleBuffer()
    {
    }

    //获取读取的数据
    virtual T& getReaderData()
    {
        if (reader_using_inst0_)
        {
            return inst0_;
        }
        else
        {
            return inst1_;
        }
    }

    //获取可写的数据
    virtual T& getWriterData()
    {
        if (reader_using_inst0_)
        {
            return inst1_;
        }
        else
        {
            return inst0_;
        }
    }

    //写完数据以后，将读写数据交换
    virtual void swap()
    {
        reader_using_inst0_ = !reader_using_inst0_;
    }

private:
    T inst0_;
    T inst1_;
    std::atomic_flag lock = ATOMIC_FLAG_INIT;
};

#endif