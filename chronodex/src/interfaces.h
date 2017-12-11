#pragma once

#include <string>
#include <types/ofBaseTypes.h>

//struct SectionSpecification {
//  float startAngleDegrees;
//  float lengthDegrees;
//};

class IDrawable {
  public:
    virtual ~IDrawable() = default;
    virtual void draw() = 0;
};

class IUpdatable {
  public:
    virtual ~IUpdatable() = default;
    virtual void update() = 0;
};

class IConnector : public IDrawable, public IUpdatable {
  public:
    virtual ~IConnector() = default;
    virtual IConnector& basePoint(ofPoint position) = 0;
    virtual ofPoint basePoint() const = 0;
    virtual IConnector& endPoint(ofPoint position) = 0;
    virtual ofPoint endPoint() const = 0;
};

class ILabel : public IDrawable, public IUpdatable {
  public:
    virtual ~ILabel() = default;
    virtual ILabel* text(std::string value) = 0;
    virtual const std::string text() const = 0;
    virtual ILabel* connector(IConnector &connector) = 0;
    virtual const IConnector& connector() const = 0;
    virtual IConnector& connectorMut() const = 0;
};

//class ISection : public IDrawable, public IUpdatable {
//  public:
//    virtual ~ISection() = 0;
//    virtual void specification(SectionSpecification spec) = 0;
//    virtual const SectionSpecification specification() = 0;
//
//    virtual void color(ofColor color) = 0;
//    virtual const ofColor color() = 0;
//};