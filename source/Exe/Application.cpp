#include "Exe/Application.h"

#include "LibA/Foo.h"

void Application::onRun()
{
    auto obj = std::make_shared<Foo>();
    
    connect(this, &Application::callFoo, obj.get(), &Foo::doSomethingFoo);
    connect(obj.get(), &Foo::callFrom, this, &Application::onLibCalls);

    emit callFoo();

    processEvents();

    exit();
}

void Application::onLibCalls(QString who)
{
    qDebug() << __FUNCTION__ << " from " << who;
}