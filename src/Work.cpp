#include "Work.hpp"

void WorkInfo::Execute() {
  if (m_callback) {
    m_callback(m_userdata);
  }
}
