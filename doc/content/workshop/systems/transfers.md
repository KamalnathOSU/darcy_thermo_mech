# Transfer System

A system to move data to and from the "parent application" and "sub-applications" of a MultiApp.

!---

Transferred data typically is handled by the Auxiliary and Postprocessor systems.

The data on the receiving application should couple to these values in the normal way and
each sub-application should be able to solve on its own

!---

## Field Interpolation

- An "interpolation" `Transfer` should be used when the domains have some overlapping geometry.
- The source field is evaluated at the destination points (generally nodes or element centroids).
- The evaluations are then put into the receiving `AuxVariable` field named `variable`.
- The direction of the transfer is specified by giving the `from_multi_app` or `to_multi_app` parameter.
- `GeneralField` versions of each transfer are implemented using a different algorithm and may be preferred. 

!listing multiapp_mesh_function_transfer/exec_on_mismatch.i block=Transfers

!---

## UserObject Interpolation

- Many `UserObjects` compute spatially-varying data that is not associated directly with a mesh
- Any `UserObject` can override `Real spatialValue(Point &)` to provide a value given a point in space
- A `UserObjectTransfer` can sample this spatially-varying data from one app and put the values into an `AuxVariable` in another

!listing multiapp_userobject_transfer/3d_1d_parent.i block=Transfers

!---

## Postprocessor Transfer

A Postprocessor transfer allows a transfer of scalar values between applications

- When transferring to a `MultiApp`, the value can either be put into a `Postprocessor` value or can be put into a constant `AuxVariable` field
- When transferring from a `MultiApp` to the parent application, the value can be interpolated from all the sub-apps into an auxiliary field

!listing multiapp_postprocessor_transfer/parent.i block=Transfers