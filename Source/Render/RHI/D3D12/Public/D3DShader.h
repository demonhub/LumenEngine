#pragma once

#include "D3DPipelineState.h"
#include "Render/RHI/Common/Public/RHIShader.h"

namespace Lumen::Render
{
    struct D3DShader : public RHIShader
    {
        D3DShader(std::string_view hlsl);
        Microsoft::WRL::ComPtr<ID3DBlob> CompileShader(std::string_view hlsl, const D3D_SHADER_MACRO* defines, std::string_view entryPoint, std::string_view target);

        Microsoft::WRL::ComPtr<ID3DBlob>                    vertexShader;
        Microsoft::WRL::ComPtr<ID3DBlob>                    pixelShader;
    };
}