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
    { };

    void draw() override
    {
      ofPushStyle();
      float a = angle();
      ofDrawBitmapString(std::to_string(a), 10, 10);
      ofSetColor(25, 25, 25);
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
      if (withinThreshold(a) || farAway()) {
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

  private:
    ofPoint m_basePoint, m_endPoint, m_midPoint;

    inline float angle() const
    {
      return ofWrapDegrees(m_basePoint.angle(m_endPoint), 0, 90);
    }

    inline bool withinThreshold(float a) {
      return a > S_ANGLE_THRESHOLD && a < 90.0f - S_ANGLE_THRESHOLD;
    }

    inline bool farAway() {
      return m_basePoint.distance(m_endPoint) > S_DISTANCE_THRESHOLD;
    }
};

float Connector::S_ANGLE_THRESHOLD = 25.0f;
float Connector::S_DISTANCE_THRESHOLD = 50.0f;

IConnector *new_connector()
{
  return new Connector();
}