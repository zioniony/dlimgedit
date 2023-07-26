#pragma once

#include "lazy.hpp"
#include "segmentation.hpp"
#include "tensor.hpp"
#include <dlimgedit/dlimgedit.hpp>

#include <onnxruntime_cxx_api.h>

#include <filesystem>
#include <mutex>
#include <type_traits>

namespace dlimg {
using Path = std::filesystem::path;
struct SegmentationModel;

class EnvironmentImpl {
  public:
    Device device = Device::cpu;
    Path model_path;
    int thread_count = 1;
    Ort::Env onnx_env;
    Ort::MemoryInfo memory_info;

    static Path verify_path(std::string_view path);

    EnvironmentImpl(Options const&);

    SegmentationModel& segmentation();

    ~EnvironmentImpl();

  private:
    Lazy<SegmentationModel> segmentation_;
};

} // namespace dlimg
