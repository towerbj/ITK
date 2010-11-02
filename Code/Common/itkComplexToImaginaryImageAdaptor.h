/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef __itkComplexToImaginaryImageAdaptor_h
#define __itkComplexToImaginaryImageAdaptor_h

#include <itkImageAdaptor.h>
#include <complex>

namespace itk
{
namespace Accessor
{
/** \class ComplexToImaginaryPixelAccessor
 * \brief Give access to the Imaginary part of a std::complex<> value
 *
 * ComplexToImaginaryPixelAccessor is templated over an internal type and an
 * external type representation. The internal type is an std::complex<T> and
 * the external part is a type T. This class cast the input applies the function
 * to it and cast the result according to the types defined as template
 * parameters
 *
 * \ingroup ImageAdaptors
 */
template< class TInternalType, class TExternalType >
class ITK_EXPORT ComplexToImaginaryPixelAccessor
{
public:
  /** External typedef. It defines the external aspect
   * that this class will exhibit. */
  typedef TExternalType ExternalType;

  /** Internal typedef. It defines the internal imaginary
   * representation of data. */
  typedef TInternalType InternalType;

  static inline void Set(TInternalType & output, const TExternalType & input)
  { output = (TInternalType)( input ); }

  static inline TExternalType Get(const TInternalType & input)
  { return (TExternalType)( input.imag() ); }
};
} // end namespace Accessor

/** \class ComplexToImaginaryImageAdaptor
 * \brief Presents a complex image as being composed of imag() part of
 * its pixels.
 *
 * Additional casting is performed according to the input and output image
 * types following C++ default casting rules.
 *
 * \ingroup ImageAdaptors
 */
template< class TImage, class TOutputPixelType >
class ITK_EXPORT ComplexToImaginaryImageAdaptor:public
  ImageAdaptor< TImage,
                Accessor::ComplexToImaginaryPixelAccessor<
                  typename TImage::PixelType,
                  TOutputPixelType >   >
{
public:
  /** Standard class typedefs. */
  typedef ComplexToImaginaryImageAdaptor Self;
  typedef ImageAdaptor< TImage, Accessor::ComplexToImaginaryPixelAccessor<
                          typename TImage::PixelType,
                          TOutputPixelType > >  Superclass;

  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(ComplexToImaginaryImageAdaptor, ImageAdaptor);
protected:
  ComplexToImaginaryImageAdaptor() {}
  virtual ~ComplexToImaginaryImageAdaptor() {}
private:
  ComplexToImaginaryImageAdaptor(const Self &); //purposely not implemented
  void operator=(const Self &);                 //purposely not implemented
};
} // end namespace itk

#endif
