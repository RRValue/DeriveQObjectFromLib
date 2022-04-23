#include "Exe/Application.h"

#include "LibA/Foo.h"

void Application::onRun()
{
    auto foo = std::make_shared<Foo>();
    
    connect(this, &Application::callFoo, foo.get(), &Foo::doSomethingFoo);
    connect(foo.get(), &Foo::callFrom, this, &Application::onLibCalls);

    emit callFoo();

    processEvents();

    exit();
}

void Application::onLibCalls(QString who)
{
    qDebug() << __FUNCTION__ << " from " << who;
}