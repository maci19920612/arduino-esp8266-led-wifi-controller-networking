#ifndef __BASE_EXECUTOR
#define __BASE_EXECUTOR
class BaseExecutor{
public:
    virtual void execute() = 0;
    virtual void init() = 0;
    virtual void dispose() = 0;
};
#endif