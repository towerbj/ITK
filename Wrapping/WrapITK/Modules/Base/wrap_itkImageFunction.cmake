WRAP_CLASS("itk::ImageFunction" POINTER)
  FOREACH(d ${WRAP_ITK_DIMS})
    # UC is required for InterpolateImageFunction
    UNIQUE(types "${WRAP_ITK_SCALAR};UC")
    FOREACH(t ${types})
      WRAP_TEMPLATE("${ITKM_I${t}${d}}${ITKM_D}${ITKM_F}"  "${ITKT_I${t}${d}},${ITKT_D},${ITKT_F}")
      WRAP_TEMPLATE("${ITKM_I${t}${d}}${ITKM_D}${ITKM_D}"  "${ITKT_I${t}${d}},${ITKT_D},${ITKT_D}")
    ENDFOREACH(t)
  ENDFOREACH(d)
END_WRAP_CLASS()
