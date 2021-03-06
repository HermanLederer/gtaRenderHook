#pragma once
#include <Engine/Common/IGPUResource.h>
#include <Engine/Common/types/string_typedefs.h>
#include <d3d11_3.h>
namespace rh::engine {

/*!
    \class CD3D1XShader
    \brief Base D3D shader class.

    This class represents shader of some sort.
*/
class D3D11Shader : public IGPUResource
{
public:
    /*!
      Initializes shader resource.
  */
    D3D11Shader();

    /*!
      Releases shader resource.
  */
    virtual ~D3D11Shader() override;

    /*!
      Sets shader to a D3D context.
  */
    virtual void Set( ID3D11DeviceContext *context ) = 0;

    /*!
      Removes shader from a D3D context.
  */
    virtual void ReSet( ID3D11DeviceContext *context ) = 0;

    /*!
      Releases resources, and reloads shader from file.
  */
    // virtual void Reload(CD3D1XShaderDefineList* localShaderDefineList =
    // nullptr);

public:
    /*!
      Compiles shader with custom entry point and shader model
  */
    HRESULT CompileShaderFromFile( const String &fileName,
                                   const String &entryPoint,
                                   const String &shaderModel,
                                   void **blobOut ) const;

protected:
    // Shader pointer.
    void *m_pShaderDC = nullptr;

    // Shader file path
    String m_sFilePath;

    // Shader entry point
    String m_sEntryPoint;

    // Shader model
    String m_sShaderModel;
};
}; // namespace rh::engine
