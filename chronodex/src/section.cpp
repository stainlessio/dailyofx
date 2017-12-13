#include "constructors.h"
#include "interfaces.h"
#include "ofColor.h"

class Section : public ISection {
  public:
    Section()
      : m_specification({})
      , m_color(ofColor::black)
      , m_label(nullptr)
    {

    }

    ~Section() {
      if (m_label) {
        delete m_label;
      }
    }
    void draw() override
    {
      ofPath arc;
      arc.setCircleResolution(30);
      arc.arc({0,0}, 100.0f, 100.0f, m_specification.startAngleDegrees,
        m_specification.startAngleDegrees + m_specification.lengthDegrees);
      arc.arcNegative({0,0}, 75.0f, 75.0f,
        m_specification.startAngleDegrees + m_specification.lengthDegrees,
        m_specification.startAngleDegrees);
      arc.close();
      arc.setFillColor(m_color);
      arc.draw();

      if (m_label) m_label->draw();
    }

    void update() override
    {
      if (m_label) m_label->update();
    }

    ISection& specification(SectionSpecification spec) override
    {
      m_specification = spec;
      return *this;
    }

    ISection& color(ofColor c) override
    {
      m_color = c;
      return *this;
    }

    const ISection& label(ILabel* label) {
      m_label = label;
      // Update label locations
      return *this;
    }

    const SectionSpecification specification() override { return m_specification; }
    const ofColor color() override { return m_color; }

  private:
    SectionSpecification m_specification;
    ofColor m_color;
    ILabel* m_label;
};

ISection *new_section(SectionSpecification spec, ofColor color, std::string value)
{
  ILabel *label = new_label(value, {1, 0}, {0, 1});
  Section *section = new Section();
  section->label(label);
  return &(section->specification(spec).color(color));
}