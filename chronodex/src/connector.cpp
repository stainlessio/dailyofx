#include "ofMain.h"
#include "constructors.h"
#include "interfaces.h"

class Connector : public IConnector
{
  public:
    static float S_ANGLE_THRESHOLD, S_DISTANCE_THRESHOLD;

    Connector()
      : m_basePoint(0, 0)
      , m_endPoint(0, 0)
      , m_midPoint(-1, -1)
    { }

    Connector(ofPoint basePoint, ofPoint endPoint)
      : m_basePoint(basePoint)
      , m_endPoint(endPoint)
      , m_midPoint(-1, -1)
    {

    }

    void draw() override
    {
      ofPushStyle();
      switch(direction()) {
        case ConnectorDirection::NW:
          ofSetColor(25, 25, 25);
          break;
        case ConnectorDirection::NE:
          ofSetColor(128, 0, 128);
          break;
        case ConnectorDirection::SE:
          ofSetColor(200, 0, 0);
          break;
        case ConnectorDirection::SW:
          ofSetColor(0, 200, 0);
          break;
      }
      ofDrawBitmapString(std::to_string(angle()), 100, 100);

      if (m_midPoint != ofPoint(-1, -1)) {
        ofDrawLine(m_basePoint, m_midPoint);
        ofDrawLine(m_midPoint, m_endPoint);
      } else {
        ofDrawLine(m_basePoint, m_endPoint);
      }

      ofPopStyle();
    }

    void update() override {
      float a = angle();
      if (withinThreshold(a) && farAway()) {
        // Calculate midpoint line
        m_midPoint = m_basePoint.getMiddle(m_endPoint);
        m_midPoint.y = m_basePoint.y;
      } else {
        m_midPoint.set(-1, -1);
      }
    }

    IConnector& basePoint(ofPoint point) override
    {
      m_basePoint = point;
      return *this;
    }

    ofPoint basePoint() const override { return m_basePoint; }

    IConnector& endPoint(ofPoint point) override
    {
      m_endPoint = point;
      return *this;
    }

    ofPoint endPoint() const override { return m_endPoint; }

    ConnectorDirection direction() const override {
      ofPoint adjusted = m_basePoint - m_endPoint;
      bool isNorth = adjusted.y > 0;
      bool isEast = adjusted.x > 0;
      if (isNorth && !isEast) return ConnectorDirection::NW;
      else if (!isNorth && !isEast) return ConnectorDirection::SW;
      else if (!isNorth && isEast) return ConnectorDirection::SE;
      else return ConnectorDirection::NE;
    }

  private:
    ofPoint m_basePoint, m_endPoint, m_midPoint;

    float angle() const
    {
      ofPoint adjusted = m_endPoint - m_basePoint;
      return ofWrapDegrees(adjusted.angle({1,0}), -180, 180);
    }

    inline bool withinThreshold(float a) {
      a = ofWrapDegrees(a, 0, 180);
      return a > S_ANGLE_THRESHOLD && a < 180.0f - S_ANGLE_THRESHOLD;
    }

    inline bool farAway() {
      return m_basePoint.distance(m_endPoint) > S_DISTANCE_THRESHOLD;
    }
};

float Connector::S_ANGLE_THRESHOLD = 25.0f;
float Connector::S_DISTANCE_THRESHOLD = 100.0f;

IConnector *new_connector(ofPoint basePoint, ofPoint endPoint)
{
  return new Connector(basePoint, endPoint);
}